#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include "curve.h"

#include <numeric>

using curvePtr = std::shared_ptr<curve>;
int main()
{
    try
    {
        std::vector<curvePtr> vc;
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, 2);
        std::uniform_real_distribution<> dist2(1.0, 20.0);

        // Populate a container
        for (int j = 0; j < 10; j++)
        {
            double r = dist2(rd), a = dist2(rd), b = dist2(rd), s = dist2(rd);
            auto c = dist(rd);
            switch (c)
            {
            case 0:
                vc.emplace_back(std::make_shared<circle>(r)); break;
            case 1:
                vc.emplace_back(std::make_shared<ellipse>(a, b)); break;
            case 2:
                vc.emplace_back(std::make_shared<helix>(r, s)); break;
            default:
                ;// can't happen
            }
        }

        // Print coordinates
        double PI4 = std::asin(1.) / 2.;    // PI/4
        for (auto v : vc)
        {
            auto p = v->Point(PI4);
            auto d = v->Derivative(PI4);
            std::cout << "point: (" << p.x << ", " << p.y << ", " << p.z << ")";
            std::cout << ", ";
            std::cout << "derivative: (" << d.x << ", " << d.y << ", " << d.z << ")";
            std::cout << std::endl;
        }

        // Populate a second container
        std::vector<curvePtr> vc2;
        std::copy_if(vc.begin(), vc.end(),
            std::back_inserter(vc2),
            [](curvePtr x)
            {
                return dynamic_cast<circle*>(x.get()) != nullptr;
            });

        // Sort the second container
        std::sort(vc2.begin(), vc2.end(), [](curvePtr a, curvePtr b)
            {
                return a->Radius() < b->Radius();
            });

        // Compute the total sum of radii
        double sum = std::accumulate(vc2.begin(), vc2.end(), 0.0,
            [](double a, curvePtr b)
            {
                return a + b->Radius();
            });
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

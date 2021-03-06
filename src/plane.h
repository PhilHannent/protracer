/* -*- mode: C++; indent-tabs-mode: nil; c-basic-offset: 2  -*- */
/*
 * This file is part of Protracer
 *
 * Protracer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Protracer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Protracer.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "hit_calculation.h"
#include "vector.h"
#include "ray.h"

namespace Protracer {

  class Plane : public Object {
  public:
    Plane(const Vector& normal, const Vector& point);

    Vector get_normal() const { return normal; }
    Vector get_point() const { return point; }

    Plane* copy() const;

    virtual HitCalculation calculate_hit(const Ray& ray) const;
    virtual void translate(const Vector& v);
    virtual void rotate(const Vector& rot);
    
    virtual Vector get_max_extent() const;
    virtual Vector get_min_extent() const;

    virtual bool is_inside(const Vector& v) const { return false; }

  private:
    Vector normal;
    Vector point;
    float d;
  };

}

#endif //PLANE_H

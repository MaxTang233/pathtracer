#include "bbox.h"

#include "GL/glew.h"

#include <algorithm>
#include <iostream>

namespace CGL {

void swap(double& d1, double& d2) {
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

bool BBox::intersect(const Ray& r, double& t0, double& t1) const {

  // TODO (Part 2.2):
  // Implement ray - bounding box intersection test
  // If the ray intersected the bouding box within the range given by
  // t0, t1, update t0 and t1 with the new intersection times.
    
    
//    double t_min_x, t_max_x;
//    double t_x1 = (max.x - r.o.x)/r.d.x;
//    double t_x2 = (min.x - r.o.x)/r.d.x;
//    if(r.d.x < 0){
//        t_min_x = t_x1;
//        t_max_x = t_x2;
//    }else{
//        t_min_x = t_x2;
//        t_max_x = t_x1;
//    }
//
//
//    double t_min_y, t_max_y;
//    double t_y1 = (max.y - r.o.y)/r.d.y;
//    double t_y2 = (min.y - r.o.y)/r.d.y;
//    if(r.d.y < 0){
//        t_min_y = t_y1;
//        t_max_y = t_y2;
//    }else{
//        t_min_y = t_y2;
//        t_max_y = t_y1;
//    }
//
//    double t_min_z, t_max_z;
//    double t_z1 = (max.z - r.o.z)/r.d.z;
//    double t_z2 = (min.z - r.o.z)/r.d.z;
//    if(r.d.z < 0){
//        t_min_z = t_z1;
//        t_max_z = t_z2;
//    }else{
//        t_min_z = t_z2;
//        t_max_z = t_z1;
//    }
//
//    double t_min = std::max(t_min_x, std::max(t_min_y, t_min_z));
//    double t_max = std::min(t_max_x, std::min(t_max_y, t_max_z));
//
//    if (t_min > t_max || t_min <=0 || t_max <= 0){
//        return false;
//    }
//
//    //has no intersection with valid interval
//    return t_min < t1 && t_max > t0;
    
    double t_max, t_min, t_max_x, t_min_x, t_max_y, t_min_y, t_max_z, t_min_z;
    t_max_x = (max.x - r.o.x) / r.d.x;
    t_min_x = (min.x - r.o.x) / r.d.x;
    if (r.d.x < 0) swap(t_max_x, t_min_x);
    t_min = t_min_x;
    t_max = t_max_x;

    t_max_y = (max.y - r.o.y) / r.d.y;
    t_min_y = (min.y - r.o.y) / r.d.y;
    if (r.d.y < 0) swap(t_max_y, t_min_y);

    if (t_min_x > t_max_y || t_min_y > t_max_x) return false;
    if (t_min_y > t_min_x) t_min = t_min_y;
    if (t_max_y < t_max_x) t_max = t_max_y;

    t_max_z = (max.z - r.o.z) / r.d.z;
    t_min_z = (min.z - r.o.z) / r.d.z;
    if (r.d.z < 0) swap(t_max_z, t_min_z);

    if (t_min > t_max_z || t_min_z > t_max) return false;
    if (t_min_z > t_min) t_min = t_min_z;
    if (t_max_z < t_max) t_max = t_max_z;

    return t_min < t1 && t_max > t0;
}

void BBox::draw(Color c, float alpha) const {

  glColor4f(c.r, c.g, c.b, alpha);

  // top
  glBegin(GL_LINE_STRIP);
  glVertex3d(max.x, max.y, max.z);
  glVertex3d(max.x, max.y, min.z);
  glVertex3d(min.x, max.y, min.z);
  glVertex3d(min.x, max.y, max.z);
  glVertex3d(max.x, max.y, max.z);
  glEnd();

  // bottom
  glBegin(GL_LINE_STRIP);
  glVertex3d(min.x, min.y, min.z);
  glVertex3d(min.x, min.y, max.z);
  glVertex3d(max.x, min.y, max.z);
  glVertex3d(max.x, min.y, min.z);
  glVertex3d(min.x, min.y, min.z);
  glEnd();

  // side
  glBegin(GL_LINES);
  glVertex3d(max.x, max.y, max.z);
  glVertex3d(max.x, min.y, max.z);
  glVertex3d(max.x, max.y, min.z);
  glVertex3d(max.x, min.y, min.z);
  glVertex3d(min.x, max.y, min.z);
  glVertex3d(min.x, min.y, min.z);
  glVertex3d(min.x, max.y, max.z);
  glVertex3d(min.x, min.y, max.z);
  glEnd();

}

std::ostream& operator<<(std::ostream& os, const BBox& b) {
  return os << "BBOX(" << b.min << ", " << b.max << ")";
}

} // namespace CGL

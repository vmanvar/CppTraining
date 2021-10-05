#pragma once

struct Triangle{
    double s1,s2,s3;
};

int perimeter(const Triangle &t1);

double area(const Triangle &t1);

void show(const Triangle &t1, const char * prefix="Triangle");
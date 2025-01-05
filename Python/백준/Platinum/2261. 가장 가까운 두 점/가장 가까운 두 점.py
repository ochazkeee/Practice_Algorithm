import math

def distance(a,b):
    return (a[0]-b[0])**2+(a[1]-b[1])**2

def closest_pair(points):
    points.sort(key=lambda x: x[0])

    def _closest_pair(points):
        if len(points)<=3:
            min_dist = math.inf
            for i in range(len(points)):
                for j in range(i+1,len(points)):
                    min_dist = min(min_dist,distance(points[i],points[j]))
            return min_dist

        mid = len(points)//2
        left=points[:mid]
        right=points[mid:]

        left_dist = _closest_pair(left)
        right_dist = _closest_pair(right)
        min_dist = min(left_dist,right_dist)

        strip=[]
        for point in points:
            if abs(point[0]-points[mid][0])<min_dist**0.5:
                strip.append(point)

        strip.sort(key=lambda x: x[1])
        for i in range(len(strip)):
            for j in range(i+1,len(strip)):
                if strip[j][1]-strip[i][1]>=min_dist**0.5:
                    break
                min_dist = min(min_dist,distance(strip[i],strip[j]))

        return min_dist
    return _closest_pair(points)

T=int(input())
points = [tuple(map(int,input().split())) for i in range(T)]

min_distance = closest_pair(points)

print(min_distance)
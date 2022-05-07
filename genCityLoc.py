import geopy.distance

class TestLoc:
    Long = 0  # Oldalra
    Lat = 0  # Fel le
    Name = ""

    def __init__(self, _long=0, _lat=0, _name=""):
        self.Name = _name
        self.Lat = _lat
        self.Long = _long

    def print(self):
        print(f"{self.Name} {self.Lat},{self.Long}", file=open("TestCities.txt", "a"))

    def distanceFrom(self,tloc):
        coord1  = (self.Lat,self.Long)
        coord2  = (tloc.Lat,tloc.Long)
        return geopy.distance.distance(coord1,coord2).km
    #TODO: make a distance fun for lat and long

LongMinMax = 180
LatMinMax = 90


def genTestLocations():
    ret = [TestLoc(_name="Start")]
    for lat in range(-LatMinMax, +LatMinMax, 5):
        if lat == -90 or lat == 90:
            ret.append(TestLoc(0, lat, f"Test_{lat}_{0}"))
        else:
            for long in range(-LongMinMax, +LongMinMax, 10):
                ret.append(TestLoc(long, lat, f"Test_{lat}_{long}"))

    return ret


n = genTestLocations()

start = n[0]
n = n[1:]
for g in n:
    print(g.distanceFrom(start))




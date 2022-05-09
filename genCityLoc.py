import geopy.distance
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm
import pandas
import geopandas as gpd


class TestLoc:
    Long: int = 0  # Oldalra
    Lat: int = 0  # Fel le
    Name = ""
    Val = 0

    def __init__(self, _long=0, _lat=0, _name=""):
        self.Name = _name
        self.Lat = _lat
        self.Long = _long

    def print(self):
        print(f"{self.Lat}|{self.Long}|0|{self.Name} ", file=open("TestCities.txt", "a"))

    def distanceFrom(self, tloc):
        coord1 = (self.Lat, self.Long)
        coord2 = (tloc.Lat, tloc.Long)
        return geopy.distance.distance(coord1, coord2).km

    def distanceFromDivided(self, tloc):
        LatDist = geopy.distance.distance((self.Lat, 0), (tloc.Lat, 0)).km
        if self.Lat < tloc.Lat:
            LatDist = -LatDist

        LongDist = geopy.distance.distance((0, self.Long), (0, tloc.Long)).km
        if self.Long < tloc.Long:
            LongDist = -LongDist

        return [LatDist, LongDist]


LongMinMax = 180
LatMinMax = 90


def genTestLocations():
    ret = [TestLoc(_name="Start")]
    for lat in range(-LatMinMax, +LatMinMax + 1, 10):
        for long in range(-LongMinMax, +LongMinMax + 1, 15):
            ret.append(TestLoc(long, lat, f"Test_{lat}_{long}"))

    return ret


f = open("TestCities.txt", "w")
f.close()
n = genTestLocations()

start = n[0]

x = []
y = []
lat = []
lon = []
delta = n.__sizeof__()
color = np.zeros((delta, delta))
fig, ax = plt.subplots(figsize=(8,6))
for g in n:
    dist = g.distanceFromDivided(start)

    x.append(dist[0])
    y.append(dist[1])
    lat.append(g.Lat)
    lon.append(g.Long)
    g.print()

x = np.array(x)
y = np.array(y)
lon = np.array(lon)
lat = np.array(lat)

Z = lat ** 2 + lon ** 2

df = pandas.DataFrame(list(zip(lat, lon, Z)), columns=["latitude", "longitude", "value"])
df.head()
# ax.scatter(x, y, Z, marker='^')
# plt.show()
countries = gpd.read_file(gpd.datasets.get_path("naturalearth_lowres"))
countries.plot(color="lightgrey", ax=ax)
df.plot(x="longitude", y="latitude", kind="scatter", c="value", colormap="hsv", ax=ax)
plt.show()

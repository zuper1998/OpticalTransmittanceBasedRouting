import geopy.distance
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm
import pandas
import geopandas as gpd
from pathlib import Path

import pandas as pd

constant = 3600 * 4


def locFromName(name: str) -> [int, int]:
    # If the town is a test
    if name.__contains__("Test"):
        loc = name.split("_")[1:]
        return [int(loc[0]), int(loc[1])]

    # Real town get location
    ret = gpd.tools.geocode(name, provider='nominatim', user_agent="my-GeoVis").geometry
    return [ret.x, ret.y]


def dataFromLine(line: str) -> [str, float]:
    parts = line.split("|")
    return [locFromName(parts[0]), float(parts[1]) * constant]  # first is the destination second is the data


def genVis(file: Path):
    datax = []
    datay = []
    dataz = []
    for line in open(file, "r").readlines():
        data = dataFromLine(line)
        datax.append(data[0][0])
        datay.append(data[0][1])
        dataz.append(data[1])

    fig, ax = plt.subplots()
    df = pd.DataFrame(list(zip(datax,datay,dataz)),
                      columns=["lat", "lon", "value"])

    print(df)
    world = gpd.read_file(gpd.datasets.get_path("naturalearth_lowres"))
    world.plot(ax=ax)
    df.plot.scatter(ax=ax,x="lat", y="lon", c="value", colormap='viridis')
    plt.show()
    plt.savefig("uwu.png")

for QSAT_FOLDER in Path('Outputs').iterdir():
    if QSAT_FOLDER.is_dir():
        for FOLDER in QSAT_FOLDER.iterdir():
            if FOLDER.name == "GeoData":
                FOLDER.joinpath("Pics").mkdir();
                for dataFile in FOLDER.iterdir():
                    genVis(dataFile)
                    dawdwadawdawd
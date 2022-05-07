from os import path
from pathlib import Path
import sys
import matplotlib.pyplot as plt
import numpy as np
import plotly.graph_objects as go
from plotly.subplots import make_subplots
import pandas as pd
import os



def visPlotly(File:path,File2:path,toprinst:path = Path(".")):
    #angle distance transmittance
    tr2=[]
    tr = []
    with open(File,"r") as file1:
        for line in file1.readlines():
            tr.append(float(line))

    #df = pd.DataFrame(dict(x=angle,y=distance,z=tr))
    with open(File2,"r") as file1:
        for line in file1.readlines():
            tr2.append(float(line))




    fig = go.Figure()
    
    
    fig.add_trace(go.Scatter(x= np.arange(len(tr2)), y=tr,name="Keresztpályás"))
    fig.add_trace(go.Scatter(x= np.arange(len(tr2)), y=tr2,name="Retrográd",line = dict(width=1)))

    # Create axis objects
    fig.update_layout(
        xaxis=dict(domain=[0.1,1.0],title="Eltelt idő [s]")
    ,
    yaxis=dict(
        title="Összefonódott kvantumbitek / másodperc",
        titlefont=dict(
            color="#1f77b4"
        ),
        tickfont=dict(
            color="#1f77b4"
        )
    ))
  
    fig.update_layout(
    width=1000,
    font = dict(size=14)
    )
    st = f"images/{os.path.basename(File)}.jpeg"
    fig.write_image(os.path.join(toprinst,st),scale=3)


visPlotly(Path(f"{sys.argv[1]}"), Path(f"{sys.argv[2]}"))
import sys
import pandas as pd
import plotly.express as px


"""
Read cluster's export table (Graph::export_nodes()) as first command line argument
Read output HTML filename as second command line argument
Visualize graph nodes on a scatter plot
"""

def main():
    args = sys.argv[1:]
    if len(args) != 2:
        print("Wrong number of arguments")
        exit()
    inp_filename, outp_filename = args

    df = pd.read_csv(inp_filename)
    df.cluster_no = df.cluster_no.replace(-1, -7)
    fig = px.scatter(df, x="lon", y="lat", color="cluster_no", hover_data=['id', 'is_outer'])
    fig.write_html(outp_filename)


if __name__ == "__main__":
    main()

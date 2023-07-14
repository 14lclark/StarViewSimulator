# Takes in a csv file with at least parallax, galactic latitude, and galactic longitude
# and creates a .dat file for use with the C++ code.

def get_labels(file):
    line = file.readline()
    while line[0] == "#":
        line = file.readline()
    label_names = line.split(",")
    labels = {}
    for i, label in enumerate(label_names):
        labels[label] = i
    return labels

def create_dat(csv):
    import re
    with open(csv, "r") as f:
        labels = get_labels(f)
        with open("stars.dat", "w") as out:
            for line in f: 
                vals = line.split(",")
                name = re.sub('\s{2,}', ' ', vals[labels['Name']])
                out.write(f"name:{name} \n")
                out.write(f"glon:{vals[labels['glon']]}\n")
                out.write(f"glat:{vals[labels['glat']]}\n")
                out.write(f"parallax:{vals[labels['parallax']]}\n")
                out.write("\n")

if __name__ == "__main__":
    create_dat("bsc5_cleaned.csv")
    print("Done")
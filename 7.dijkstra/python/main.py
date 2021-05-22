import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input_file")
args = parser.parse_args()

if __name__ == "__main__":
    with open(args.input_file, "r") as f:
        pass

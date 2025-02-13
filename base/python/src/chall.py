import os

if os.path.exists("/home/ctf/flag"):
    with open("/home/ctf/flag", "r") as f:
        print(f.read())
else:
    print("Flag not found")
    exit(1)

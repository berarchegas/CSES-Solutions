import os

for dname, dirs, files in os.walk(r"C:\Users\berna\Unicamp\Competitive Programming\CSES\CSES-Solutions\src"):
    for fname in files:
        num = fname[0:4]
        nome = fname[7:len(fname) - 4]
        fpath = os.path.join(dname, fname)
        with open(fpath) as f:
            s = f.read()
        s = s.replace("""/*
Problem Name: {nome}
Problem Link: https://cses.fi/problemset/task/{num}
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/""".format(nome = nome, num = num), """// {nome}
//
// Problem name: {nome}
// Problem Link: https://cses.fi/problemset/task/{num}
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
""".format(nome = nome, num = num)) 
        with open(fpath, "w") as f:
            f.write(s)
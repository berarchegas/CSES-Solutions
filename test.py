fname = "1068 - Weird Algorithm.cpp"
nome = fname[7:len(fname) - 4]
num = fname[0:4]

s = """/*
Problem name: {nome}
Problem Link: https://cses.fi/problemset/task/{num}
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/""".format(nome = nome, num = num)
s = s.replace("""/*
Problem name: {nome}
Problem Link: https://cses.fi/problemset/task/{num}
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/""".format(nome = nome, num = num), """// {nome}
//
// Problem name: {nome}
// Problem Link: https://cses.fi/problemset/task/{num}
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
""".format(nome = nome, num = num))
print(s)
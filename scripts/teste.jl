include("/Users/rafaeldias/repositories/c/teste/scripts/MetodoDeslocamentos.jl")

# Se tiver carga distribuída usar essas reações
function reacoes(P, L, a)
    RA = (P * (L - a)^2 * (L + 2 * a)) / L^3
    RB = (P * a^2 * (3 * L - 2 * a)) / L^3
    MA = ((-P * a) / L^2) * (L - a)^2
    MB = ((-P * a^2) / L^2) * (L - a)

    if (a / 2) <= a
        return [RA; MA; RB; -MB]
    else
        return [RB; MB; RA; -MA]
    end
end

# matrizes de rigidez dos elementos
E = 2.1e6
I = (0.2 * 0.3^3) / 12.0
k1 = Elementos2D.matriz_rigidez_viga(E, I, 1.0)
k2 = Elementos2D.matriz_rigidez_viga(E, I, 1.75)
k3 = Elementos2D.matriz_rigidez_viga(E, I, 2.75)

# nós dos elementos
e1 = [1, 2, 3, 4]
e2 = [3, 4, 5, 6]
e3 = [5, 6, 7, 8]

# graus de liberdades
u = [3, 4, 5, 6]

# restrições
r = [1, 2, 7, 8]

# matriz de rigidez global
K = zeros(length(u) + length(r), length(u) + length(r))
K[e1, e1] = k1
K[e2, e2] += k2
K[e3, e3] += k3

# submatrizes
KU = zeros(length(u), length(u)) # graus de liberdades
KR = zeros(length(r), length(r)) # restrições
KU = K[u, u]
KR = K[r, r]

# matrizes de Forças
F = zeros(length(u) + length(r))
U = zeros(length(u) + length(r))
FU = zeros(length(u))
FR = zeros(length(r))

P = -5
L = 5.5/2

# Carregamentos nodais
F[3] = P
F[5] = P

FU[1:length(u)] = F[u]
FR[1:length(r)] = F[r]

# calcular deslocamentos
UU = KU \ FU
U[u] += UU

# elemento 1
f1 = k1 * U[e1] - F[e1]

# elemento 2
f2 = k2 * U[e2] - F[e2]

F_ = zeros(length(u) + length(r))
F_[e1] = f1
F_[e2] += f2

R = K * U - F

global index = 1
for n in R
    print("$(index % 2 == 0 ? "M$(index)" : "F$(index)"): $(round(n, digits=3)) $(index % 2 == 1 ? "kN" : "kN.m")\t\t\tu$(index): $(index % 2 == 1 ? round(U[index], sigdigits=3) : round(rad2deg(U[index]), sigdigits=3)) $(index % 2 == 1 ? "m" : "graus")\n")
    global index += 1
end

println()

r1 = k1 * U[e1] - F[e1]
r2 = k2 * U[e2] - F[e2]
r3 = k3 * U[e3] - F[e3]

println("Elemento 1")
print("VA: $(round(r1[1], digits=3)) kN\n")
print("MA: $(round(r1[2], digits=3)) kN.m\n")
print("VB: $(round(r1[3], digits=3)) kN\n")
print("MB: $(round(r1[4], digits=3)) kN.m\n\n")

println("Elemento 2")
print("VA: $(round(r2[1], digits=3)) kN\n")
print("MA: $(round(r2[2], digits=3)) kN.m\n")
print("VB: $(round(r2[3], digits=3)) kN\n")
print("MB: $(round(r2[4], digits=3)) kN.m\n\n")

println("Elemento 3")
print("VA: $(round(r3[1], digits=3)) kN\n")
print("MA: $(round(r3[2], digits=3)) kN.m\n")
print("VB: $(round(r3[3], digits=3)) kN\n")
print("MB: $(round(r3[4], digits=3)) kN.m\n\n")

# U[1] = U[2] = 0.04
# K * U - F
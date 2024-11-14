
module Data

module carregamentos
# referencia apendice B - Propriedades Geometricas - Pappalardo Jr, Alfonso. Aplicações
# práticas e desafios estruturais com mef. São Paulo: Oficina de Textos, 2023.

module B11
# Viga biengastada com carga distribuída
function f(p::Float64, L::Float64, E::Float64, I::Float64)
    return (-p * L^4) / (384 * E * I)
end

function RA(p::Float64, L::Float64)
    return (p * L) / 2
end

function RB(p::Float64, L::Float64)
    return RA(p, L)
end

function MA(p::Float64, L::Float64)
    return (-p * L^2) / 12
end

function MB(p::Float64, L::Float64)
    return MA(p, L)
end

function Mmax(p::Float64, L::Float64)
    return (p * L) / 24
end

function xMmax(L::Float64)
    return L / 2
end
end
end

module Propriedades

module Geometricas
# referencia apendice A - Propriedades Geometricas - Pappalardo Jr, Alfonso. Aplicações
# práticas e desafios estruturais com mef. São Paulo: Oficina de Textos, 2023.
module A1
export A, Ix, Iy, Iz, f

function A(b::Float64, h::Float64)::Float64
    return b * h
end

function Iz(b::Float64, h::Float64)::Float64
    return (b * h^3) / 12
end

function Iy(b::Float64, h::Float64)::Float64
    return (b^3 * h) / 12
end

function Ix(b::Float64, h::Float64)::Float64
    return (h * b^3) * (((1 / 3) - 0.21 * (b / h)) * (1 - ((b^4) / (12 * h^4))))
end

function f(A::Float64, As::Float64)
    return A / As
end
end

module A2
export A, Ix, Iy, Iz, f

function A(D::Float64)::Float64
    return (pi / 4) * D^2
end

function Iz(D::Float64)
    return (pi / 64) * D^4
end

function Iy(D::Float64)
    return Iz(D)
end

function Ix(D::Float64)
    return (pi / 32) * D^4
end

function f(A::Float64, As::Float64)
    return A / As
end
end

end
end
end
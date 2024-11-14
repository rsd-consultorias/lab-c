include("ConsoleUtil.jl")
include("TabelasLajes.jl")
using Printf

function clear()
    print("\033c")
end

struct Laje
    lx::Float64
    ly::Float64
    h::Float64
    Q::Float64
    E::Float64
    id::String
    caso::Int
    alfa::Float64
end

lajes = []

function ler_dados_laje()
    print("id: ")
    id = readline()

    print("lx (m): ")
    lx = parse(Float64, readline())

    print("ly (m): ")
    ly = parse(Float64, readline())

    print("h (cm): ")
    h = parse(Float64, readline())

    print("Q (kN/m2): ")
    Q = parse(Float64, readline())

    print("E (GPa): ")
    E = parse(Float64, readline())

    print("Caso [1~9]: ")
    caso = parse(Int, readline())

    push!(lajes, Laje(lx, ly, h, Q, E, id, caso, 1.0))
    clear()
end

function calcular_alfa(lambda::Float64, caso::Int)::Float64
    x = round(round(lambda / 0.05) * 0.05, digits=2)
    if x <= 2.00
        return TabelasLajes.COEFICIENTE_ALFA[x][caso]
    else
        return TabelasLajes.COEFICIENTE_ALFA[0.0][caso]
    end
end

function calcular_laje()
    global lajes = []
    # ler_dados_laje()
    print_header()
    push!(lajes, Laje(3.0, 4.0, 10.0, 4.1, 24.0, "L1", 4, 3.92))
    push!(lajes, Laje(3.0, 3.0, 10.0, 4.1, 24.0, "L2", 4, 2.42))
    push!(lajes, Laje(4.0, 4.0, 10.0, 4.1, 24.0, "L3", 3, 3.2))
    push!(lajes, Laje(4.0, 8.0, 8.0, 8.1, 24.0, "L4", 3, 3.2))
    push!(lajes, Laje(3.25, 3.90, 10.0, 4.1, 24.0, "L5", 7, 2.72))

    println("* CÁLCULO DE FLECHAS (F) ELÁSTICAS EM LAJES - CARGA UNIFORME\n")

    println("ID     Caso  lx         ly         h          Q          Ecs        λ          α          F Imediata αf         F Final    F Limite   Verificação")
    println("       [1~9] (m)        (m)        (cm)       (kN/m2)    (GPa)                            (cm)                  (cm)       (cm)")
    println("------ ----- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- --------------------")
    for laje in lajes
        lambda = laje.ly / laje.lx
        alfa = calcular_alfa(lambda, laje.caso)
        flechaImediata = 100 * ((laje.Q * 10e3) * ((laje.lx^4) * alfa) / ((laje.E * 10e9) * ((laje.h / 100)^3) * 100))
        flechaTotal = 1.46
        flechaFinal = (flechaImediata * flechaTotal) + flechaImediata
        flechaLimite = (100 * laje.lx) / 250
        verificacao = flechaLimite > flechaFinal ? "OK" : "NOK FLECHA"

        if laje.lx > laje.ly
            verificacao = "ERRO: lx>ly"
        end
        @printf "%-6s %+5s %10.2f %10.2f %10.2f %10.2f %10.2f %10.2f %10.2f %10.3f %10.3f %10.3f %10.3f %-20s\n" laje.id laje.caso laje.lx laje.ly laje.h laje.Q laje.E lambda alfa flechaImediata flechaTotal flechaFinal flechaLimite verificacao
    end
end
module Elementos2D

export matriz_rigidez_mola, matriz_rigidez_mola_rotacional, matriz_rigidez_trelica
export matriz_rigidez_viga, matriz_rigidez_portico, matriz_rigidez_grelha
export matriz_rigidez_placa, matriz_rigidez_solido

function matriz_rigidez_mola(k::Float64)::Matrix{Float64}
    # deslocamentos: u1=x u2=x2
    k_ij = zeros(2, 2)
    k_ij = [
        k -k
        -k k
    ]

    return k_ij
end

function matriz_rigidez_mola_rotacional(k::Float64, phi::Float64)::Matrix{Float64}
    # deslocamentos: u1=x u2=x2
    k_ij = zeros(2, 2)
    k_ij = [
        k -k
        -k k
    ] * phi

    return k_ij
end

function matriz_rigidez_trelica(E::Float64, A::Float64, L::Float64)::Matrix{Float64}
    # deslocamentos: u1=x1 u2=y1 u3=x2 u4=y2
    k_ij = zeros(4, 4)
    k_ij = [
        (E*A)/L 0.0 (-E*A)/L 0.0
        0.0 0.0 0.0 0.0
        (-E*A)/L 0.0 (E*A)/L 0.0
        0.0 0.0 0.0 0.0
    ]

    return k_ij
end

function matriz_rigidez_viga(E::Float64, I::Float64, L::Float64, g::Float64=0.0)::Matrix{Float64}
    # deslocamentos: u1=y1 u2=z1 u3=y2 u4=z2 --> zi é rotação devido ao momento
    k_ij = zeros(4, 4)
    if g != 0.0
        # 'g' diferente de zero, usar teoria de viga de Timoshenko
        # Ver NBR6118, se relação da L/h da viga for inferior a 2 em vigas biapoiadas, deve
        # levar em conta a energia de deformação devido ao cizalhamento
        k_ij = (E * I) / (1 + 2 * g) * [
            12/L^3 6/L^2 -12/L^3 6/L^2
            6/L^2 (4/L)*(1+g/2) -6/L^2 (2/L)*(1-g)
            -12/L^3 -6/L^2 12/L^3 -6/L^2
            6/L^2 (2/L)*(1-g) -6/L^2 (4/L)*(1+g/2)
        ]
    else
        # 'g' igual a zero, usar teoria de viga de Bernoulli
        k_ij = [
            (12*E*I)/L^3 (6*E*I)/L^2 (-12*E*I)/L^3 (6*E*I)/L^2
            (6*E*I)/L^2 (4*E*I)/L (-6*E*I)/L^2 (2*E*I)/L
            (-12*E*I)/L^3 (-6*E*I)/L^2 (12*E*I)/L^3 (-6*E*I)/L^2
            (6*E*I)/L^2 (2*E*I)/L (-6*E*I)/L^2 (4*E*I)/L
        ]
    end

    return k_ij
end

function matriz_rigidez_portico()::Matrix{Float64}
    # deslocamentos: u1=x1 u2=y1 u3=z1 u4=x2 u5=y2 u6=z2 --> zi é rotação devido ao momento
    k_ij = zeros(6, 6)
    k_ij = [
        (E*A)/L 0.0 0.0 (-E*A)/L 0.0 0.0
        0.0 (12*E*I)/L^3 (6*E*I)/L^2 0.0 (-12*E*I)/L^3 (6*E*I)/L^2
        0.0 (6*E*I)/L^2 (4*E*I)/L 0.0 (-6*E*I)/L^2 (2*E*I)/L
        (-E*A)/L 0.0 0.0 (E*A)/L 0.0 0.0
        0.0 (-12*E*I)/L^3 (-6*E*I)/L^2 0.0 (12*E*I)/L^3 (-6*E*I)/L^2
        0.0 (6*E*I)/L^2 (2*E*I)/L 0.0 (-6*E*I)/L^2 (4*E*I)/L
    ]

    return k_ij
end

function matriz_rigidez_grelha()::Matrix{Float64}
    k_ij = zeros(6, 6)

    return k_ij
end

function matriz_rigidez_placa()::Matrix{Float64}
    k_ij = zeros(6, 6)

    return k_ij
end

function matriz_rigidez_solido()::Matrix{Float64}
    k_ij = zeros(6, 6)

    return k_ij
end

end
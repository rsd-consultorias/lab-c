# Se tiver carga pontual usar essas reações
function carga_pontual(P, L, a)
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

# Se tiver carga distribuída usar essas reações
function carga_distribuida(P, L)
    RA = (P * L^2) / 2
    RB = (P * L^2) / 2
    MA = (P * L^2) / 12
    MB = (-P * L^2) / 12
    
    return [RA; MA; RB; -MB]
end
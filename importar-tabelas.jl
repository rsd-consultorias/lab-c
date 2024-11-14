linhas = []
for i in 1:25
    push!(linhas, "")
end

linha = "2,50 2,50 2,62 2,50 2,73 2,50 2,83 2,50 2,92 2,50 3,00 2,50 3,08 2,50 3,15 2,50 3,21 2,50 3,28 2,50 3,33 2,50 3,39 2,50 3,44 2,50 3,48 2,50 3,53 2,50 3,57 2,50 3,61 2,50 3,65 2,50 3,68 2,50 3,72 2,50 3,75 2,50 5,00 2,50"
colunas = 2
i = 1
j = 1
for coluna in split(linha, " ")
    if (i < colunas)
        linhas[j] *= "$(replace(coluna, "," => ".")), "
        global i += 1
    else
        linhas[j] *= "$(replace(coluna, "," => ".")), "
        println(linhas[j])
        global i = 1
        global j += 1
    end
end

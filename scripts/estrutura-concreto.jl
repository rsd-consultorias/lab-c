include("NBR6118.jl")
include("NBR6120.jl")
include("NBR6123.jl")
include("Estrutura.jl")

using LinearAlgebra

function rigidez_global()
    
end

function solve()
    
end


# Suponha que o arquivo "model.nastran" contém os dados NASTRAN
nodes, elements_cbar, loads, moments, degreeOfFreedom = Estrutura.load_nastran("/Users/rafaeldias/repositories/c/teste/data/casa.rsd")
Estrutura.write_dxf("/Users/rafaeldias/repositories/c/teste/data/model.dxf", nodes, elements_cbar)

# Exibir os dados carregados
println("\nNós:")
println("\nID\tCoordenadas")
for (id, node) in nodes
    println("$(node.id)\t$(node.x), $(node.y), $(node.z)")
end

println("\nElementos:")
println("\nID\tName\tNó 1\t\tNó 2")
for (id, element) in elements_cbar
    println("$(element.id)\t$(element.name)\t$(nodes[element.node1].x), $(nodes[element.node1].y), $(nodes[element.node1].z)\t$(nodes[element.node2].x), $(nodes[element.node2].y), $(nodes[element.node2].z)")
end

println("\nCarregamentos:")
for (id, load) in loads
    println(load)
end

println("\nLiberdades:")
for(id, dof) in degreeOfFreedom
    println(dof)
end

module Main

include("Data.jl")
include("Analysis.jl")
include("PostProcessing.jl")

using .Data
using .Analysis
using .PostProcessing

function run_analysis()
    # Carregar dados
    nodes, elements, loads = load_nastran("data/model.nastran")
    
    # Calcular deslocamentos
    displacements = calculateDisplacements(nodes, elements, loads)
    
    # Calcular reações e matriz de rigidez global
    reactions = calculateReactions(nodes, elements, displacements)
    global_stiffness_matrix = calculateGlobalStiffnessMatrix(nodes, elements)
    
    # Pós-processamento e visualização
    generate_report(reactions, displacements)
    write_dxf("output/model.dxf", nodes, elements)

    println("Análise concluída.")
end

end # module Main

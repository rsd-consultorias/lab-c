using DelimitedFiles

module Estrutura
# Definição da estrutura para nós
struct Node
    id::Int
    x::Float64
    y::Float64
    z::Float64
end

# Definição da estrutura para elementos
struct Element
    id::Int
    node1::Int
    node2::Int
    name::String
end

# Definição da estrutura para carregamentos nodais
struct Load
    node_id::Int
    fx::Float64
    fy::Float64
    fz::Float64
end

struct Moment
    node_id::Int
    mx::Float64
    my::Float64
    mz::Float64
end

# Definição da estrutura para elementos CTRIA3 (triangular)
struct CTRIA3
    id::Int
    node1::Int
    node2::Int
    node3::Int
end

# Definição da estrutura para elementos CQUAD4 (quadrilátero)
struct CQUAD4
    id::Int
    node1::Int
    node2::Int
    node3::Int
    node4::Int
end

# Definição da estrutura para MASS (massa concentrada)
struct Mass
    node_id::Int
    mass::Float64
end

# Definição da estrutura para SPC (condições de contorno)
struct SPC
    node_id::Int
    dof::Vector{String}
end

function load_nastran(filename::String)
    nodes = Dict{Int,Node}()
    elements_cbar = Dict{Int,Element}()
    elements_cquad4 = Dict{Int,CQUAD4}()
    elements_ctria3 = Dict{Int,CTRIA3}()
    loads = Dict{Int,Load}()
    moments = Dict{Int,Moment}()
    degreeOfFreedom = Dict{Int,SPC}()

    # Leitura do arquivo
    lines = readlines(filename)

    for line in lines
        fields = split(line, ",")
        if startswith(line, "GRID")
            id = parse(Int, fields[2])
            x = parse(Float64, fields[3])
            y = parse(Float64, fields[4])
            z = parse(Float64, fields[5])
            nodes[id] = Node(id, x, y, z)
        elseif startswith(fields[1], "CBAR") || startswith(fields[1], "CBEAM") || startswith(fields[1], "CELAS")
            id = parse(Int, fields[2])
            node1 = parse(Int, fields[3])
            node2 = parse(Int, fields[4])
            elements_cbar[id] = Element(id, node1, node2, last(fields))
        elseif startswith(line, "CQUAD4")
            id = parse(Int, fields[2])
            node1 = parse(Int, fields[3])
            node2 = parse(Int, fields[4])
            node3 = parse(Int, fields[5])
            node4 = parse(Int, fields[6])
            elements_cquad4[id] = CQUAD4(id, node1, node2, node3, node4)
        elseif startswith(line, "CTRIA3")
            id = parse(Int, fields[2])
            node1 = parse(Int, fields[3])
            node2 = parse(Int, fields[4])
            node3 = parse(Int, fields[5])
            elements_ctria3[id] = CTRIA3(id, node1, node2, node3)
        elseif startswith(line, "FORCE")
            node_id = parse(Int, fields[2])
            fx = parse(Float64, fields[4])
            fy = parse(Float64, fields[5])
            fz = parse(Float64, fields[6])
            loads[node_id] = Load(node_id, fx, fy, fz)
        elseif startswith(line, "MOMENT")
            node_id = parse(Int, fields[2])
            mx = parse(Float64, fields[4])
            my = parse(Float64, fields[5])
            mz = parse(Float64, fields[6])
            moments[node_id] = Moment(node_id, mx, my, mz)
        elseif startswith(line, "SPC")
            node_id = parse(Int, fields[2])
            dof = split(strip(fields[3]), "")
            degreeOfFreedom[node_id] = SPC(node_id, dof)
        end
    end

    return nodes, elements_cbar, loads, moments, degreeOfFreedom
    # return nodes, elements_cbar, elements_cquad4, elements_ctria3, loads, moments
end

function write_dxf(filename::String, nodes::Dict{Int,Node}, elements::Dict{Int,Element})
    open(filename, "w") do file
        # Escrever cabeçalho do DXF
        write(file, "0\nSECTION\n2\nHEADER\n0\nENDSEC\n")
        write(file, "0\nSECTION\n2\nTABLES\n0\nENDSEC\n")
        write(file, "0\nSECTION\n2\nBLOCKS\n0\nENDSEC\n")
        write(file, "0\nSECTION\n2\nENTITIES\n")

        # Escrever nós como pontos DXF
        for node in values(nodes)
            write(file, "0\nPOINT\n8\n0\n10\n$(node.x)\n20\n$(node.y)\n30\n$(node.z)\n")
        end

        # Escrever elementos como linhas DXF
        for element in values(elements)
            node1 = nodes[element.node1]
            node2 = nodes[element.node2]
            write(file, "0\nLINE\n8\n0\n10\n$(node1.x)\n20\n$(node1.y)\n30\n$(node1.z)\n")
            write(file, "11\n$(node2.x)\n21\n$(node2.y)\n31\n$(node2.z)\n")
        end

        # Fechar seção de entidades e o arquivo DXF
        write(file, "0\nENDSEC\n0\nEOF\n")
    end
end
end
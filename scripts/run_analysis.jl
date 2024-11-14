include("ConsoleUtil.jl")
include("lajes.jl")

opcao = ""

function opcao_menu()
    println("\n[L]Lajes  [V]Vigas  [P]Pilares  [F]Fundações  [C]Contenções\n[X]Sair\n")
    print("Comando: ")
    global opcao = readline()
end

while opcao != "sair"
    print_header()
    if opcao == "L"
        # print_header()
        calcular_laje()
    elseif opcao == "X"
        exit(0)
    else
        # print_header()
    end

    opcao_menu()
end
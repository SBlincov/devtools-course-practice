// Copyright 2017 Kozlov Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include "include/Application.h"
#include "include/Graph.h"

Application::Application() {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an optimal way calculator application.\n\n" +
        "Pleaseprovide arguments in the following format:\n\n" +

        "  $ " + appname + "<size> <start_node_index> <edge1> <edge2> ... <edgeN>\n" +
        "WHERE <edgeN> = <weightN> <nodeIndexA> <nodeIndexB>\n\n" +

        "ATTENTION:\n"
        "\n*All arguments should be unsingned integer values!" +
        "\n*The max value of any argument is " + std::to_string(INF) + "!" +
        "\n*If there is no edge between nodes, the result of optimal way" +
        "between them will be 'inf'" +
        "\n*The number of arguments should be > 2 and 2 + n, where the 'n' is a multiple of 3!" +
        "\n*Carefully observe the format where typing the edges!";
};

int Application::ParseInt(const char* arg) {
    try {
        return std::stoi(arg);
    }
    catch (std::string& str) {
        throw str;
    }
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    }

    if (argc >= 3 && (argc - 3) % 3 == 0) {
        return true;
    }

    Help(argv[0], "ERROR: Incorrect arguments num.\n\n");
    return false;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    std::ostringstream stream;


    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size_ = ParseInt(argv[1]);
        args.start_node_ = ParseInt(argv[2]);
        args.connected_nodes_ = (argc - 3) / 3;
        for (int i = 3; i < args.connected_nodes_; i++) {
            args.edges_.push_back(ParseInt(argv[i]));
        }
    }
    catch (std::string& str) {
        return str;
    }

    Graph graph(args.size_);
    for (int i = 0; i < args.connected_nodes_ * 3; i += 3) {
        graph.AddEdge(args.edges_[i], args.edges_[i + 1], args.edges_[i + 2]);
    }
    vector<unsigned int> res = graph.Dijkstra(args.start_node_);
    for (unsigned int i = 0; i < graph.GetSize(); i++) {
        if (res[i] < INF) {
            stream << res[i];
        }
        else if (res[i] >= INF) {
            stream << "inf";
        }
        message_ += stream.str() + " ";
    }
    message_.pop_back();
    return message_;
}


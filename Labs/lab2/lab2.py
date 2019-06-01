import random


def random_graph(n, p):
    graph = [[] for j in range(n)]

    for i in range(0, n):
        for j in range(0, n):
            if (i < j):
                q = random.random()
                if (q < p):
                    graph[i].append(j)
                    graph[j].append(i)

    return graph



def largest_size(graph, t):

    for start in range(0, len(graph) - t + 1):

        visited = set()
        queue = [start]
        while queue:
            vertex = queue.pop(0)
            if vertex not in visited:
                visited.add(vertex)
                for i in graph[vertex]:
                    if i not in visited:
                        queue.append(i)

        if len(visited) >= t:
            return 1

    return 0


n = 40
p_pos = [0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0]



for p in p_pos:
    p1 = p / n
    percent = 0
    for i in range(0, 500):
        graph = random_graph(n, p1)
        x = largest_size(graph, 30)
        if (x == 1):
            percent = percent + 1

    percent = percent / float(5)
    print(p, percent)





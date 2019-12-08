def main(file_name)
  edges = File.read(file_name).split("\n").map{|line| line.split(')')}
  h = {}

  edges.each do |(src, dest)|
    h[dest] = src
  end

  total = h.keys.reduce(0) do |memo, node|
    memo += find_path(node, h)
    memo
  end
  puts total
end

def find_path(node, h)
  path_size = 0
  current_node = node
  while(h[current_node])
    path_size += 1
    current_node = h[current_node]
  end
  return path_size
end

main('02.input')

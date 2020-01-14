arr = File.read(ARGV.first).split('').map(&:to_i)

ARGV[1].to_i.times do 
  result = arr.map.with_index do |item, idx|
    pattern = [0, 1, 0, -1].flat_map{|i| [i] * (idx + 1)}
    pattern = pattern * (arr.size / pattern.size + 1)
    pattern[1..-1].first(arr.size).zip(arr).map{|i| i.first * i.last}.sum.abs % 10
  end
  arr = result
end
puts arr.first(8).join

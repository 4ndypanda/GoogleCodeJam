require 'set'

def main
  tests = gets.to_i
  (1..tests).each do |t|
    n = gets.to_i
    if n == 0
      puts "Case ##{t}: INSOMNIA"
      next
    end

    # There are ten digits we need to find
    digits_seen = Set.new
    current_number = 0
    while digits_seen.size < 10
      current_number += n
      current_number.to_s.each_char { |digit| digits_seen.add(digit) }
    end

    puts "Case ##{t}: #{current_number}"
  end
end

if __FILE__ == $PROGRAM_NAME
  main
end

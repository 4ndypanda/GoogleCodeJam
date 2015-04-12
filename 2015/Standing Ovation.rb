def main
  tests = gets.to_i
  (1..tests).each do |t|
    max_shyness, audience = gets.split
    standing_members, needed_friends = audience[0].to_i, 0
    (1..max_shyness.to_i).each do |shyness_level|
      current_members = audience[shyness_level].to_i
      next if current_members == 0

      # If there are enough people standing, then the current audience members
      # for the current shyness level will stand. Otherwise we need to add
      # friends equal to the difference between the current shyness level and
      # the number of standing members to get the current members to stand.
      if standing_members >= shyness_level
        standing_members += current_members
      else
        needed_friends += shyness_level - standing_members
        standing_members = current_members + shyness_level
      end
    end
    puts "Case ##{t}: #{needed_friends}"
  end
end

if __FILE__ == $PROGRAM_NAME
  main
end

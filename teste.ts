const phase = "batata".split("")

const result = phase.reduce<Record<string, number>>((letterCount, char) => {
  const newValue = { ...letterCount };

  if (typeof newValue[char] === "undefined") {
    return {
      ...newValue,
      [char]: 1
    }
  }
  newValue[char]++
  return newValue

}, {})

console.log(JSON.stringify(result, null, 2))
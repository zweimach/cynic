enum Morse {
    Dot,
    Dash,
}

const charDelim = [Morse];

function parse(input: string): Morse[] {
    const output: Morse[] = [];
    for (const c of input) {
        switch (c) {
            case "A":
                output.concat([Morse.Dot, Morse.Dash]);
                break;
            default:
        }
    }
    return output;
}

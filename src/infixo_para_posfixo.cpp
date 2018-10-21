std::string inflix_to_postfix( std::string infix) {
	std::stack< symbol > s; // pilha auxiliar para converter de infixo p/ postixo.

	std::string postfix; // vai conter a expressao de saaida do formato posfixo.

	//percorrer cada elemento de entrada.
	for( auto c : inflix) {
		//tratar cada token de acordo com seu valor.
		if( is_operand(c) ) // operando vai para a saida diretamente.
			posfix += c;
		else if (is_opening_scope(c))
			s.push(c); // vai para pilha sem levar em consideracao quem está por 
		else if (is_closing_scope(c)) {
			// enquanto nao encontrar o "irmao" ')' na pilha, (re)mova
			// todos os operadores que lá est]ao para a saida.
			while( not is_closing_scope( s.top() ) ) {
				postfix += s.top();
				s.pop();
			}
			// lembre-se de jogar fora o ')' que esta no topo.
			s.pop();
		}
		else if ( is_operator(c)) { //+, -,*,%, /, ^
			while( not s.empty() and has_higher_or_eq_precedence( s.top(), c)) {
				// remover elementos da pilha para saida.
				postfix += s.top();
				s.pop();
			}
			// lembre que o que chega sempre entra na pilha (fica em espera).
			s.push(c); //vai pro topo da pilha.
		}
		else { //espaco em branco

		// Do nothing.
		}
	}

	//lembrar de descarregar os operadores pendentes na pilha, se existirem.
	while( not s.empty() ) {
		postfix += s
	}
}
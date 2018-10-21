value_type evaluate_postfix( std::string postfix) {
	std::stack< value_type > s;

	// percorrer a fila de simbolos, um por um.
	for (auto c: postfix) {
		if ( is_operand (c) ) {
			s.push( char2integer(c))
		}
		else if (is_operator(c) ) {
			value_type op2 = s.top(); 
			s.pop();
			value_type op1 = s.top(); 
			s.pop();
			value_type rsult = execute_operator(op1, op2, c);
			s.push( result );
		}
	}

	return s.top(); // o resultado deve estar no topo da pilha.
}

value_type execute_operator(value_type v1, value_type v2, sumbol op) {
	switch (op) {
		case'^' : return po(v1, v2);
		case'*' : return v1*v2;
		case '/' : if(v2==0)  throw std::sruntime_error("Divisao por zero!");
		return v1/v2;
		case '%': if(v2==0) throw std::sruntime_error("Divisao por zero!");
		return v1%v2;
		case'+' : return v1+v2;
		case'-' : return v1-v2;
		default: assert (false); return -1
	}
}


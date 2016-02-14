library IEEE;
use IEEE.STD_LOGIC_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all; 
use IEEE.numeric_std.all;

entity D9_C1 is
	 port(
		 rst : in STD_LOGIC;
		 cin : in STD_LOGIC;
		 a : in STD_LOGIC_VECTOR(7 downto 0);
		 b : in STD_LOGIC_VECTOR(7 downto 0);
		 sel : in STD_LOGIC_VECTOR(3 downto 0);
		 y : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D9_C1;
architecture D9_C1 of D9_C1 is
begin						  
	process(sel)   
	variable temp:std_logic_vector (7 downto 0);
	begin  
		case sel is	   
			when "0000" => temp:=a;
			when "0001"	=> temp:=a+1;
			when "0010"	=> temp:=a-1;
			when "0011"	=> temp:=b;
			when "0100"	=> temp:=b+1;
			when "0101"	=> temp:=b-1;
			when "0110"	=> temp:=a+b;
			when "0111"	=> temp:=a + b + cin;
			when "1000"	=> temp:=NOT a;
			when "1001"	=> temp:=NOT b;
			when "1010"	=> temp:=a AND b;
			when "1011"	=> temp:=a OR b;
			when "1100"	=> temp:=a NAND b;
			when "1101"	=> temp:=a NOR b;
			when "1110"	=> temp:=a XOR b;
			when others	=> temp:=a XNOR b ;
	  end case;
	  y <=temp;	
	  end process;
end D9_C1;
-- rst=10khz; cin=5Mhz; a,b= counter 0=>1111111 50ns; sel= random  100ns;
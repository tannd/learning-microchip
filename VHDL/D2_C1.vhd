library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D2_C1 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 Q : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D2_C1;

architecture D2_C1 of D2_C1 is 
	type state is (s0,s1,s2,s3,s4,s5,s6,s7,s8,s9);
	signal s:state;
begin

	next_state:process(rst,clk)
	begin
		if (rst='1') then s<=s0;
		else
			if (rising_edge(clk)) then 
				case s is
					when s0 => s <=s1;
					when s1 => s <=s2;
					when s2 => s <=s3;
					when s3 => s <=s4;
					when s4 => s <=s5;
					when s5 => s <=s6;
					when s6 => s <=s7;
					when s7 => s <=s8;
					when s8 => s <=s9;
					when s9 => s <=s0;
				end case;
			end if;
		end if;
	end process;
	output_state:process(s)
	begin
		case s is
			when s0=> Q<="00000000";
			when s1=> Q<="00000001";
			when s2=> Q<="00000010";
			when s3=> Q<="00000011";
			when s4=> Q<="00000100";
			when s5=> Q<="00000101";
			when s6=> Q<="00000110";
			when s7=> Q<="00000111";
			when s8=> Q<="00001001";
			when s9=> Q<="00001010";
		end case;
	end process;
end D2_C1;
-- rst = 0.5Mhz, clk=10Mhz

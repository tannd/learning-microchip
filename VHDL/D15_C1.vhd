library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D15_C1 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end D15_C1;
architecture D15_C1 of D15_C1 is 
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
                when s0 => seg<= x"C0";
                when s1 => seg<= x"F9";
                when s2 => seg<= x"A4";
                when s3 => seg<= x"B0";
                when s4 => seg<= x"99";
                when s5 => seg<= x"92";
                when s6 => seg<= x"82";
                when s7 => seg<= x"F8";
                when s8 => seg<= x"80";
                when s9 => seg<= x"90";
		end case; 
	end process;
end D15_C1;
-- rst=0.5Mhz; clk=20Mhz;
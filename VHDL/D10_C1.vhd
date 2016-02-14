library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D10_C1 is
	 port(
		 rst : in STD_LOGIC;
		 d : in BIT;
		 clk : in STD_LOGIC;
		 y : out STD_LOGIC
	     );
end D10_C1;

architecture D10_C1 of D10_C1 is  
type state is (s0,s1,s2,s3);
signal s:state;
begin
	next_state:process(rst,clk)
	begin
		if (rst='1') then s<=s0;
		else
			if (rising_edge(clk)) then
				case s is
					when s0 => 
					if d='0' then s <=s0; else s<=s1;
					end if;
					when s1 => 
					if d='0' then s <=s2; else s<=s3;
					end if;
					when s2 => 
					if d='0' then s <=s0; else s<=s1;
					end if;
					when s3 => 
					if d='0' then s <=s2; else s<=s3;
					end if;
				end case;
			end if;
		end if;
	end process;
	output:process(s,clk)
	begin
		if (rising_edge(clk)) then 
			if ((s=s3) and (d='1'))	then
				y<='1';
			else y<='0';
			end if;
		end if;
	end process;

end D10_C1;
--rst=500khz; d= random 100ns; clk=	5Mhz;
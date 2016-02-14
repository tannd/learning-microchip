library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity D11_C1 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 y : out STD_LOGIC;
		 d : in BIT
	     );
end D11_C1;

architecture D11_C1 of D11_C1 is 
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
					if d='0' then s <=s1; else s<=s0;
					end if;
					when s1 => 
					if d='0' then s <=s3; else s<=s2;
					end if;
					when s2 => 
					if d='0' then s <=s1; else s<=s0;
					end if;
					when s3 => 
					if d='0' then s <=s3; else s<=s2;
					end if;
				end case;
			end if;
		end if;
	end process;
	output:process(s,clk)
	begin
		if (rising_edge(clk)) then 
			if ((s=s3) and (d='0'))	then
				y<='1';
			else y<='0';
			end if;
		end if;
	end process;

end D11_C1;
 --rst=100khz; d= random 100ns; clk=5Mhz;
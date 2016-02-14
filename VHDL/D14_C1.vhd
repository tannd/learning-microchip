library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity D14_C1 is
	 port(
		 rst : in STD_LOGIC;
		 clk : in STD_LOGIC;
		 seg : out STD_LOGIC_VECTOR(6 downto 0)
	     );
end D14_C1;

architecture D14_C1 of D14_C1 is
signal temp:STD_Logic_vector (3 downto 0);
begin
	process (clk,rst)
	begin  
		if(rst='1') then
			temp<="0000";
		elsif (rising_edge(clk)) then
			if(temp="1111") then temp<="0000";
			else temp <= temp+1;
			end if;
		end if;	
	end process;
	process(temp)
	begin
		case temp is
				WHEN "0000"=>seg<="1111110";
				WHEN "0001"=>seg<="0110000";
				WHEN "0010"=>seg<="1101101";
				WHEN "0011"=>seg<="1111001";
				WHEN "0100"=>seg<="0110011";
				WHEN "0101"=>seg<="1011011";
				WHEN "0110"=>seg<="1011111";
				WHEN "0111"=>seg<="1110000";
				WHEN "1000"=>seg<="1111111";
				WHEN "1001"=>seg<="1111011";
				WHEN "1010"=>seg<="1110111";
				WHEN "1011"=>seg<="0011111";
				WHEN "1100"=>seg<="1001110";
				WHEN "1101"=>seg<="0111101";
				WHEN "1110"=>seg<="1001111";
				WHEN "1111"=>seg<="1000111";
				WHEN OTHERS=>seg<="XXXXXXX";
		end case;
	end process;
end D14_C1;
 -- rst=500khz; clk=20Mhz;
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
ENTITY D13_C1 IS
	PORT ( 
		rst:in std_logic;
		clk:IN STD_logic;
		seg:out STD_Logic_vector(7 downto 0));
END D13_C1;
ARCHITECTURE D13_C1 of D13_C1 IS 
signal temp: std_logic_vector(3 downto 0);
signal gray: std_logic_vector(3 downto 0);
begin
	process (clk,rst)
	begin  
		if(rst='1') then
			temp<="0000";
			gray<="0000";
		elsif (rising_edge(clk)) then
			if(temp="1001") then temp<="0000";
			else temp <= temp+1;
			end if;
		  gray(3)<=temp(3);
		  for i in 2 downto 0 loop
			  gray(i)<= temp(i+1) xor temp(i);
		  end loop;
		end if;	
	end process;
	process(gray)
	begin
		case gray is
                when "0000" => seg<= x"C0";
                when "0001" => seg<= x"F9";
                when "0011" => seg<= x"A4";
                when "0010" => seg<= x"B0";	
                when "0110" => seg<= x"99";
                when "0111" => seg<= x"92";
                when "0101" => seg<= x"82";
                when "0100" => seg<= x"F8";
                when "1100" => seg<= x"80";
                when "1101" => seg<= x"90";
				when others =>NULL;
		end case;
	end process;
end D13_C1;
--d= counter 100 ns;
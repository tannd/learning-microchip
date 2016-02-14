-------------------------------------------------------------------------------
--
-- Title       : ALU_function
-- Design      : de1
-- Author      : phamthanh1992@hotmail.com
-- Company     : homes
--
-------------------------------------------------------------------------------
--
-- File        : ALU_function.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL; 
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity ALU_function is
	 port(
		 cin : in STD_LOGIC;
		 a : in STD_LOGIC_VECTOR(7 downto 0);
		 b : in STD_LOGIC_VECTOR(7 downto 0);
		 sel : in STD_LOGIC_VECTOR(3 downto 0);
		 y : out STD_LOGIC_VECTOR(7 downto 0)
	     );
end ALU_function;

--}} End of automatically maintained section

architecture ALU_function of ALU_function is	   
function hamlogic
(
	x1,x2: in std_logic_vector(7 downto 0);
	sel: in std_logic_vector(2 downto 0)
) return std_logic_vector is 
variable y1:  std_logic_vector(7 downto 0); 
  begin  
       
   		if sel = "000" then y1:= not x1;
		elsif sel ="001" then y1:= not x2;
		elsif sel ="010" then y1:= x1 and x2;
		elsif sel ="011" then y1:= x1 or x2;
		elsif sel ="100" then y1:= x1 nand x2;
		elsif sel ="101" then y1:= x1 nor x2;
		elsif sel ="110" then y1:= x1 xor x2;
		elsif sel ="111" then y1:= x1 xnor x2;	
		end if ;
		return y1;
end  hamlogic;
function hamsohoc
(
	a,b: in std_logic_vector(7 downto 0);
	sel: in std_logic_vector(2 downto 0);
	cin: in std_logic
) return std_logic_vector is 
variable y2:  std_logic_vector(7 downto 0); 
  begin  
   	if sel ="000" then y2:= a;
		elsif sel ="001" then y2:=a+1;
		elsif sel ="010" then y2:=a-1;
		elsif sel ="011" then y2:=b;
		elsif sel ="100" then y2:=b+1;
		elsif sel ="101" then y2:=b-1;
		elsif sel ="110" then y2:=a+b;
		elsif sel ="111" then y2:=a+b+cin;
		end if;
		return y2;
  end  hamsohoc; 
function hammux
(
	y1,y2: in std_logic_vector(7 downto 0) ;
	sel : in STD_LOGIC
) return std_logic_vector is 
variable z:  std_logic_vector(7 downto 0);   
  begin  
   	if sel='0'then z:=y1;
	else z:=y2;
	end if;
	return z;
  end  hammux;
  
signal w1,w2: std_logic_vector (7 downto 0);
begin

process(sel,a,b,cin)
begin
	w1<=hamlogic(a,b,sel(2 downto 0));
	w2<=hamsohoc(a,b,sel(2 downto 0),cin);
	y<=hammux(w1,w2,sel(3));
	
end process;	

end ALU_function;

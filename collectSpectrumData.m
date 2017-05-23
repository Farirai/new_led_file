%P1 leaf l1
%P2 leaf l2
%tometoes g1
%tomatoes g2
%tomatoes r1
%tomatoes r2

%fwrite - uncomment commands when arduino is connected 

prompt = 'Enter bit/int for LEDs';
x = input(prompt, 's');
x = str2num(x);
data = [];
%fwrite(s, x); 


while (true)
prompt = 'Enter Charater';
y = input(prompt, 's');

if ((strcmp(y, 's') == 1))
%fwrite(s,0); 
break;
end

result = [y;x;num2cell(wrapper.getSpectrum(0))];
data = [data; result'];
end
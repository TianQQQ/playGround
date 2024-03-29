function g = sigmoid(z)
%SIGMOID Compute sigmoid functoon
%   J = SIGMOID(z) computes the sigmoid of z.

% You need to return the following variables correctly 
g = zeros(size(z));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the sigmoid of each value of z (z can be a matrix,
%               vector or scalar).

len = size(z,2);
dep = size(z,1);
for i = 1:len
    for j = 1:dep
        g(j,i) = 1/(1 + exp(-z(j,i)));
    end
end




% =============================================================

end

function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

%num_iters = 10;
%alpha = 3;

for iter = 1:num_iters
	
	J_like_1 = 0;
	J_like_2 = 0;
    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
	

	for i = 1:m		
		h = theta(1) + theta(2) * X(i,2)
		J_like_1 += (h - y(i)) * X(i,1);
		J_like_2 += (h - y(i)) * X(i,2);
	end
	theta(1) -= alpha / m * J_like_1
	theta(2) -= alpha / m * J_like_2

    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta)

end

end


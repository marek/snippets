
<!--
in assets.rb add:
Rails.application.config.assets.precompile += %w(my_source_code.js)


in form.erb:
---
<%= javascript_include_tag "my_source_code" %>

<h2>Object View</h2>

<%= form_tag object_path, method: :put do %>
  State:
  <br/>
  Object id:
  <br/>
  <%= text_field_tag :object_id, @my_object&.id, required: true %>
  <br/>
  <%= submit_tag 'Submit.' %>
<% end %>
---



-->
document.addEventListener("DOMContentLoaded", function(){
    document.getElementById("my_object_id").addEventListener("change",
        function(event) {
            this.form.action = "<%= Rails.application.routes.url_helpers.object_path %>" + "/" + this.value
        }
    );
});


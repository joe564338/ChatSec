<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CreateKeysTable extends Migration
{

    public function up() {
        Schema::create('keys', function (Blueprint $table) {
            $table->increments('id');
            $table->string('username')->unique();
            $table->string('signing_key');
            $table->string('encryption_key');
            $table->timestamps();
        });
    }

    public function down() {
        Schema::drop('keys');
    }
}
